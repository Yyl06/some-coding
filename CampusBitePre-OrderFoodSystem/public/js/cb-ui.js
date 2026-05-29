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

  var notificationsMuted = null;
  var notificationsStorageKey = "cb-notifications-muted";

  function isNotificationsMuted() {
    if (notificationsMuted !== null) return notificationsMuted;
    try {
      notificationsMuted = window.localStorage.getItem(notificationsStorageKey) === "true";
    } catch (_e) {
      notificationsMuted = false;
    }
    return notificationsMuted;
  }

  function setNotificationsMuted(next) {
    notificationsMuted = Boolean(next);
    try {
      window.localStorage.setItem(
        notificationsStorageKey,
        notificationsMuted ? "true" : "false"
      );
    } catch (_e) {
      // ignore
    }

    var toggles = document.querySelectorAll("[data-notifications-toggle]");
    toggles.forEach(function (toggle) {
      if (toggle && toggle.type === "checkbox") {
        toggle.checked = notificationsMuted;
      }
    });
  }

  function bindNotificationsToggle() {
    var toggles = document.querySelectorAll("[data-notifications-toggle]");
    if (!toggles.length) return;

    var muted = isNotificationsMuted();
    toggles.forEach(function (toggle) {
      if (toggle && toggle.type === "checkbox") {
        toggle.checked = muted;
        toggle.addEventListener("change", function () {
          setNotificationsMuted(toggle.checked);
        });
      }
    });
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

        // If another handler (e.g. inline confirm) already cancelled, do nothing.
        if (event.defaultPrevented) return;

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
      false
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

  function createBadge(statusText) {
    var status = String(statusText || "Pending");
    var lowered = status.toLowerCase();
    var muted = lowered === "pending" || lowered === "cancelled" || lowered === "rejected";
    var span = document.createElement("span");
    span.className = "cb-badge " + (muted ? "cb-badge--muted" : "cb-badge--primary");
    span.textContent = status;
    return span;
  }

  function buildItemsCell(items) {
    var td = document.createElement("td");
    if (!items || !items.length) return td;

    items.forEach(function (it, idx) {
      var line = document.createElement("div");
      line.className = "cb-muted";
      line.textContent = String(it.foodName || "") + " × " + String(it.quantity || 0);
      if (idx < items.length - 1) line.textContent += ",";
      td.appendChild(line);

      if (it.remark) {
        var remark = document.createElement("div");
        remark.className = "cb-muted";
        remark.style.fontSize = "12px";
        remark.textContent = "Remark: " + String(it.remark);
        td.appendChild(remark);
      }
    });

    return td;
  }

  function renderOrdersTable(orders, role) {
    var tableCard = document.getElementById("orders-table");
    if (!tableCard) return;
    var emptyCard = document.getElementById("orders-empty");
    var tbody = tableCard.querySelector("tbody");
    if (!tbody) return;

    if (!orders || !orders.length) {
      if (emptyCard) emptyCard.style.display = "";
      tableCard.style.display = "none";
      return;
    }

    if (emptyCard) emptyCard.style.display = "none";
    tableCard.style.display = "";

    while (tbody.firstChild) {
      tbody.removeChild(tbody.firstChild);
    }

    orders.forEach(function (order) {
      var tr = document.createElement("tr");
      tr.setAttribute("data-order-id", String(order.id || ""));

      var tdDate = document.createElement("td");
      if (order.createdAt) {
        var time = document.createElement("time");
        time.className = "js-local-time";
        time.setAttribute("datetime", order.createdAt);
        time.textContent = new Date(order.createdAt).toLocaleString();
        tdDate.appendChild(time);
      }
      tr.appendChild(tdDate);

      if (role === "student" || role === "admin") {
        var tdMerchant = document.createElement("td");
        tdMerchant.textContent = String(order.merchant || "");
        tr.appendChild(tdMerchant);
      }

      if (role === "merchant" || role === "admin") {
        var tdStudent = document.createElement("td");
        tdStudent.textContent = String(order.student || "");
        tr.appendChild(tdStudent);
      }

      tr.appendChild(buildItemsCell(order.items || []));

      var tdTotal = document.createElement("td");
      tdTotal.textContent = "RM " + String(order.totalPriceText || "");
      tr.appendChild(tdTotal);

      var tdStatus = document.createElement("td");
      tdStatus.appendChild(createBadge(order.status || "Pending"));
      tr.appendChild(tdStatus);

      if (role === "student") {
        var tdComplete = document.createElement("td");
        if (String(order.status || "") === "Ready") {
          var completeForm = document.createElement("form");
          completeForm.className = "inline-form";
          completeForm.method = "POST";
          completeForm.action = "/orders/" + String(order.id) + "/complete";
          completeForm.setAttribute(
            "onsubmit",
            "return confirm('Mark this order as completed?');"
          );
          var completeBtn = document.createElement("button");
          completeBtn.type = "submit";
          completeBtn.textContent = "Complete";
          completeForm.appendChild(completeBtn);
          tdComplete.appendChild(completeForm);
        } else {
          var completeDisabled = document.createElement("button");
          completeDisabled.type = "button";
          completeDisabled.disabled = true;
          completeDisabled.textContent = "Complete";
          tdComplete.appendChild(completeDisabled);
        }
        tr.appendChild(tdComplete);

        var tdCancel = document.createElement("td");
        if (String(order.status || "") === "Pending") {
          var cancelForm = document.createElement("form");
          cancelForm.className = "inline-form";
          cancelForm.method = "POST";
          cancelForm.action = "/orders/" + String(order.id) + "/cancel";
          cancelForm.setAttribute(
            "onsubmit",
            "return confirm('Cancel this order?');"
          );
          var cancelBtn = document.createElement("button");
          cancelBtn.type = "submit";
          cancelBtn.textContent = "Cancel";
          cancelForm.appendChild(cancelBtn);
          tdCancel.appendChild(cancelForm);
        } else {
          var cancelDisabled = document.createElement("button");
          cancelDisabled.type = "button";
          cancelDisabled.disabled = true;
          cancelDisabled.textContent = "Cancel";
          tdCancel.appendChild(cancelDisabled);
        }
        tr.appendChild(tdCancel);
      }

      if (role === "merchant" || role === "admin") {
        var tdUpdate = document.createElement("td");
        var updateForm = document.createElement("form");
        updateForm.className = "inline-form";
        updateForm.method = "POST";
        updateForm.action = "/orders/" + String(order.id) + "/status";

        var select = document.createElement("select");
        select.name = "status";
        select.style.width = "170px";

        var options = [
          "Pending",
          "Confirmed",
          "Ready",
          "Completed",
          "Cancelled",
          "Rejected",
        ];

        options.forEach(function (opt) {
          var option = document.createElement("option");
          option.value = opt;
          option.textContent = opt;
          if (opt === "Cancelled") option.disabled = true;
          if (opt === order.status) option.selected = true;
          select.appendChild(option);
        });

        var disabledUpdate =
          String(order.status || "") === "Cancelled" ||
          String(order.status || "") === "Rejected";
        if (disabledUpdate) select.disabled = true;

        var saveBtn = document.createElement("button");
        saveBtn.type = "submit";
        saveBtn.textContent = "Save";
        if (disabledUpdate) saveBtn.disabled = true;

        updateForm.appendChild(select);
        updateForm.appendChild(saveBtn);
        tdUpdate.appendChild(updateForm);
        tr.appendChild(tdUpdate);
      }

      tbody.appendChild(tr);
    });

    formatLocalTimes();
  }

  function pollOrderNotifications() {
    var POLL_INTERVAL_MS = 5000;
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
        if (isNotificationsMuted()) return;
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
      if (isNotificationsMuted()) return;
      var student = order.student || "student";
      showToast("New order from " + student, "info");
    }

    function startStudentPoll() {
      var storageKey = "cb-order-status-cache-student";
      var cache = loadCache(storageKey);
      var initialSync = true;

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
              if (prev && prev !== status && !initialSync) {
                notifyForStatus(order, status);
              }
              nextCache[id] = status;
            });

            cache = nextCache;
            saveCache(storageKey, nextCache);
            initialSync = false;
          })
          .catch(function () {
            // ignore poll errors
          });
      }

      checkUpdates();
      window.setInterval(checkUpdates, POLL_INTERVAL_MS);
    }

    function startOrdersTablePoll() {
      if (!document.getElementById("orders-table")) return;

      function refresh() {
        fetch("/orders/list", { credentials: "same-origin" })
          .then(function (res) {
            return res.ok ? res.json() : null;
          })
          .then(function (data) {
            if (!data || !Array.isArray(data.orders)) return;
            renderOrdersTable(data.orders, data.role || "student");
          })
          .catch(function () {
            // ignore
          });
      }

      refresh();
      window.setInterval(refresh, POLL_INTERVAL_MS);
    }

    function startMerchantPoll() {
      var storageKey = "cb-order-status-cache-merchant";
      var cache = loadCache(storageKey);
      var initialSync = true;

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

              if (!prev && !initialSync) {
                notifyMerchantNew(order);
              } else if (prev !== status && (status === "Cancelled" || status === "Rejected")) {
                if (!isNotificationsMuted()) {
                  showToast(
                    "Order from " + (order.student || "student") + " was " + status,
                    "error"
                  );
                }
              }

              nextCache[id] = status;
            });

            cache = nextCache;
            saveCache(storageKey, nextCache);
            initialSync = false;
          })
          .catch(function () {
            // ignore poll errors
          });
      }

      checkUpdates();
      window.setInterval(checkUpdates, POLL_INTERVAL_MS);
    }

    fetch("/auth/session", { credentials: "same-origin" })
      .then(function (res) {
        return res.ok ? res.json() : null;
      })
      .then(function (data) {
        if (!data || !data.loggedIn) return;
        startOrdersTablePoll();
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
    bindNotificationsToggle();
    pollOrderNotifications();
  });
})();
