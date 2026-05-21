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

  document.addEventListener("DOMContentLoaded", function () {
    activateNavLinks();
    handleQueryToasts();
    preventDoubleSubmits();
    confirmLogout();
  });
})();
