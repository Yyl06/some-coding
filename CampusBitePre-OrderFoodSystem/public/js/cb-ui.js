/* CampusBite UI helpers: active nav + toast notifications */

(function () {
  "use strict";

  function normalizePathname(pathname) {
    if (!pathname) return "/";
    // Remove trailing slash except root
    return pathname.length > 1 && pathname.endsWith("/")
      ? pathname.slice(0, -1)
      : pathname;
  }

  function ensureToastHost() {
    var existing = document.querySelector(".cb-toast-host");
    if (existing) return existing;

    var host = document.createElement("div");
    host.className = "cb-toast-host";
    host.setAttribute("aria-live", "polite");
    host.setAttribute("aria-relevant", "additions");
    document.body.appendChild(host);
    return host;
  }

  function showToast(message, variant) {
    if (!message) return;

    var host = ensureToastHost();
    var toast = document.createElement("div");
    toast.className = "cb-toast" + (variant ? " cb-toast--" + variant : "");
    toast.setAttribute("role", "status");

    var text = document.createElement("div");
    text.className = "cb-toast-text";
    text.textContent = message;

    var close = document.createElement("button");
    close.className = "cb-toast-close";
    close.type = "button";
    close.setAttribute("aria-label", "Close");
    close.textContent = "×";
    close.addEventListener("click", function () {
      toast.remove();
    });

    toast.appendChild(text);
    toast.appendChild(close);
    host.appendChild(toast);

    // Auto-dismiss (kept simple; no animations)
    window.setTimeout(function () {
      if (toast && toast.isConnected) toast.remove();
    }, 4500);
  }

  function activateNavLinks() {
    var current = normalizePathname(window.location.pathname);
    var links = document.querySelectorAll(".cb-nav-link[href]");

    links.forEach(function (link) {
      try {
        var url = new URL(link.getAttribute("href"), window.location.origin);
        var hrefPath = normalizePathname(url.pathname);

        if (hrefPath === "/") {
          if (current === "/") link.classList.add("cb-nav-link--active");
          return;
        }

        // Exact match or within section (e.g. /foods and /foods/add)
        if (current === hrefPath || current.startsWith(hrefPath + "/")) {
          link.classList.add("cb-nav-link--active");
        }

        // Special-case for menu links that include an ID
        if (hrefPath.startsWith("/menu/") && current.startsWith("/menu/")) {
          link.classList.add("cb-nav-link--active");
        }
      } catch (_e) {
        // ignore malformed hrefs
      }
    });
  }

  function handleQueryToasts() {
    var url = new URL(window.location.href);
    var params = url.searchParams;

    var success = params.get("success");
    var error = params.get("error");
    var info = params.get("info");

    if (success) showToast(success, "success");
    if (error) showToast(error, "error");
    if (info) showToast(info, "info");

    if (success || error || info) {
      params.delete("success");
      params.delete("error");
      params.delete("info");

      var next = url.pathname + (params.toString() ? "?" + params.toString() : "") + url.hash;
      window.history.replaceState({}, "", next);
    }
  }

  function preventDoubleSubmits() {
    document.addEventListener(
      "submit",
      function (event) {
        var form = event.target;
        if (!form || form.nodeName !== "FORM") return;

        // Only guard POST forms (adds/checkout/status updates)
        var method = (form.getAttribute("method") || "GET").toUpperCase();
        if (method !== "POST") return;

        if (form.dataset && form.dataset.cbSubmitted === "true") {
          event.preventDefault();
          return;
        }

        if (form.dataset) form.dataset.cbSubmitted = "true";

        var buttons = form.querySelectorAll('button[type="submit"], input[type="submit"]');
        buttons.forEach(function (btn) {
          try {
            btn.disabled = true;
          } catch (_e) {
            // ignore
          }
        });
      },
      true
    );
  }

  function confirmLogout() {
    var links = document.querySelectorAll('a[href="/auth/logout"]');
    links.forEach(function (link) {
      link.addEventListener("click", function (event) {
        if (!window.confirm("Logging out from this session?")) {
          event.preventDefault();
        }
      });
    });

    var forms = document.querySelectorAll('form[action="/auth/logout"]');
    forms.forEach(function (form) {
      form.addEventListener("submit", function (event) {
        if (!window.confirm("Logging out from this session?")) {
          event.preventDefault();
        }
      });
    });
  }

  function setupQuantityControls() {
    document.addEventListener("click", function (event) {
      var btn = event.target.closest(".cb-qty-btn");
      if (!btn) return;

      var wrap = btn.closest(".cb-qty");
      if (!wrap) return;

      var input = wrap.querySelector("input[type=number]");
      if (!input) return;

      var min = parseInt(input.getAttribute("min"), 10);
      var max = parseInt(input.getAttribute("max"), 10);
      var step = parseInt(input.getAttribute("step"), 10);
      if (!Number.isFinite(step) || step <= 0) step = 1;

      var current = parseInt(input.value, 10);
      if (!Number.isFinite(current)) current = Number.isFinite(min) ? min : 1;

      var action = btn.getAttribute("data-qty-action");
      var next = action === "down" ? current - step : current + step;

      if (Number.isFinite(min)) next = Math.max(min, next);
      if (Number.isFinite(max)) next = Math.min(max, next);

      input.value = next;
      input.dispatchEvent(new Event("change", { bubbles: true }));
    });
  }

  function formatLocalTimes() {
    var els = document.querySelectorAll('.js-local-time');
    els.forEach(function (el) {
      try {
        var dt = el.getAttribute('datetime');
        if (!dt) return;
        var d = new Date(dt);
        if (isNaN(d.getTime())) return;
        // show localized string and set tooltip to ISO
        el.textContent = d.toLocaleString();
        el.setAttribute('title', d.toISOString());
      } catch (_e) {
        // ignore
      }
    });
  }

  function pollOrderNotifications() {
    function loadCache(storageKey) {
      try {
        var raw = window.localStorage.getItem(storageKey);
        return raw ? JSON.parse(raw) || {} : {};
      } catch (_e) {
        return {};
      }
    }

    function saveCache(storageKey, next) {
      try {
        window.localStorage.setItem(storageKey, JSON.stringify(next));
      } catch (_e) {
        // ignore
      }
    }

    function notifyForStatus(order, status) {
      var merchant = order.merchant || "merchant";
      if (status === "Ready") {
        showToast("Order from " + merchant + " is Ready", "success");
      } else if (status === "Confirmed") {
        showToast("Order from " + merchant + " is Confirmed", "info");
      } else if (status === "Rejected" || status === "Cancelled") {
        showToast("Order from " + merchant + " was " + status, "error");
      }
    }

    function notifyMerchantNew(order) {
      var student = order.student || "student";
      showToast("New order from " + student, "info");
    }

    function startStudentPoll() {
      var storageKey = "cb-order-status-cache-student";
      var cache = loadCache(storageKey);

      function checkUpdates() {
        fetch("/orders/notifications", { credentials: "same-origin" })
          .then(function (res) {
            return res.ok ? res.json() : null;
          })
          .then(function (data) {
            if (!data || !Array.isArray(data.orders)) return;

            var nextCache = Object.assign({}, cache);
            data.orders.forEach(function (order) {
              var id = String(order.id || "");
              if (!id) return;
              var status = String(order.status || "Pending");
              var prev = nextCache[id];
              if (prev && prev !== status) {
                notifyForStatus(order, status);
              }
              nextCache[id] = status;
            });

            cache = nextCache;
            saveCache(storageKey, nextCache);
          })
          .catch(function () {
            // ignore poll errors
          });
      }

      checkUpdates();
      window.setInterval(checkUpdates, 30000);
    }

    function startMerchantPoll() {
      var storageKey = "cb-order-status-cache-merchant";
      var cache = loadCache(storageKey);

      function checkUpdates() {
        fetch("/orders/notifications/merchant", { credentials: "same-origin" })
          .then(function (res) {
            return res.ok ? res.json() : null;
          })
          .then(function (data) {
            if (!data || !Array.isArray(data.orders)) return;

            var nextCache = Object.assign({}, cache);
            data.orders.forEach(function (order) {
              var id = String(order.id || "");
              if (!id) return;
              var status = String(order.status || "Pending");
              var prev = nextCache[id];

              if (!prev) {
                notifyMerchantNew(order);
              } else if (prev !== status && (status === "Cancelled" || status === "Rejected")) {
                showToast("Order from " + (order.student || "student") + " was " + status, "error");
              }

              nextCache[id] = status;
            });

            cache = nextCache;
            saveCache(storageKey, nextCache);
          })
          .catch(function () {
            // ignore poll errors
          });
      }

      checkUpdates();
      window.setInterval(checkUpdates, 30000);
    }

    fetch("/auth/session", { credentials: "same-origin" })
      .then(function (res) {
        return res.ok ? res.json() : null;
      })
      .then(function (data) {
        if (!data || !data.loggedIn) return;
        if (data.role === "student") {
          startStudentPoll();
        } else if (data.role === "merchant") {
          startMerchantPoll();
        }
      })
      .catch(function () {
        // ignore
      });
  }

  document.addEventListener("DOMContentLoaded", function () {
    activateNavLinks();
    handleQueryToasts();
    preventDoubleSubmits();
    confirmLogout();
    setupQuantityControls();
    formatLocalTimes();
    pollOrderNotifications();
  });
})();
