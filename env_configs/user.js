
user_pref("browser.cache.disk.enable", false); // Disable disk cache
user_pref("browser.cache.offline.enable", false); // Disable offline cache
 
// Network Configuration
user_pref("network.http.referer.XOriginPolicy", 1); // Send referer to same eTLD sites [Set to "0" if you experience issues with 2FA logins]
user_pref("network.predictor.enabled", false); // Disable predictor
user_pref("network.prefetch-next", false); // Disable link prefetching
user_pref("network.dns.disablePrefetch", true); // Disable DNS prefetching

user_pref("browser.region.network.url", "");
user_pref("captivedetect.canonicalURL", "");
user_pref("dom.security.https_only_mode", false); // HTTPS only mode [Enable HTTPS mode with "true"]
user_pref("network.captive-portal-service.enabled", false); // Disable captive portal
user_pref("network.connectivity-service.enabled", false);
user_pref("network.cookie.cookieBehavior", 1); // Block 3p cookies
user_pref("network.security.esni.enabled", true);
user_pref("network.trr.bootstrapAddress", "");
user_pref("network.trr.mode", 3); // DNS-over-HTTPS [Enable strict DoH with "3"]
 
// Device Fingerprinting
user_pref("beacon.enabled", false); // Disable beacon
user_pref("dom.battery.enabled", false); // Disable battery status
user_pref("dom.gamepad.enabled", false); // Disable USB devices
user_pref("dom.push.enabled", false); // Disable push notifications
user_pref("dom.serviceWorkers.enabled", false); // Disable service workers
user_pref("general.useragent.override", "Mozilla/5.0 (X11; Linux x86_64; rv:78.0) Gecko/20100101 Firefox/78.0"); // Useragent [Masks Ubuntu User-Agent; redundant with RFP; remove if on Windows]
user_pref("dom.webnotifications.enabled", false); // Disable desktop notifications
user_pref("geo.enabled", false); // Disable geolocation
user_pref("geo.provider.network.url", "");
user_pref("geo.provider-country.network.url", "");
user_pref("media.navigator.enabled", true); // Disable mic and camera
user_pref("media.peerconnection.enabled", true); // Disable WebRTC
user_pref("media.webspeech.synth.enabled", false); // Disable speech synthesis
//user_pref("privacy.donottrackheader.enabled", true); // Send DNT header
user_pref("privacy.firstparty.isolate", true); // Restrict data to domain level
user_pref("privacy.resistFingerprinting", false); // RFP [Enable RFP with "true"]
user_pref("webgl.disabled", true); // Disable WebGL

// suspicious
user_pref("dom.event.clipboardevents.enabled", true); // Disable clipboard events
user_pref("dom.allow_cut_copy", true);

// Telemetry & Shield
user_pref("app.normandy.api_url", "");
user_pref("app.normandy.enabled", false); // Disable shield telemetry
user_pref("app.shield.optoutstudies.enabled", false);
user_pref("datareporting.healthreport.uploadEnabled", false);
user_pref("datareporting.policy.dataSubmissionEnabled", false); // Disable all technical data
user_pref("datareporting.policy.firstRunURL", "");
user_pref("toolkit.telemetry.server", "");
user_pref("toolkit.telemetry.unified", false); // Disable Fx telemetry

// // Add-ons Behavior
// user_pref("extensions.getAddons.cache.enabled", false);
// user_pref("extensions.getAddons.discovery.api_url", "");
user_pref("extensions.htmlaboutaddons.recommendations.enabled", false); // Disable add-ons recommendations

// // Features & Media Plugins
user_pref("accessibility.force_disabled", 1);
user_pref("extensions.pocket.enabled", false); // Disable pocket
user_pref("extensions.screenshots.disabled", true); // Disable screenshots
user_pref("extensions.webcompat-reporter.enabled", false); // Disable report this site
user_pref("identity.fxaccounts.enabled", true); // Disable Fx accounts
user_pref("media.eme.enabled", false); // Disable EME for DRM content
user_pref("media.gmp-gmpopenh264.enabled", true); // Disable OpenH264 for WebRTC
user_pref("media.gmp-manager.url", "");
user_pref("media.gmp-provider.enabled", false);
user_pref("media.gmp-widevinecdm.enabled", false); // Disable Widevine CDM
user_pref("privacy.trackingprotection.cryptomining.enabled", false);
user_pref("privacy.trackingprotection.enabled", false); // Redundant with uBlock0
user_pref("privacy.trackingprotection.fingerprinting.enabled", false);
user_pref("privacy.trackingprotection.pbmode.enabled", false);

// // Miscellaneous
user_pref("browser.aboutConfig.showWarning", false); // Disable modify warning
// user_pref("browser.download.autohideButton", false);
user_pref("browser.shell.checkDefaultBrowser", false); // Disable default check
user_pref("browser.uidensity", 1); // Compact density
user_pref("browser.urlbar.openViewOnFocus", true); // Disable enlargement
user_pref("findbar.highlightAll", true); // Highlight text search
user_pref("reader.parse-on-load.enabled", false); // Disable reader
user_pref("toolkit.legacyUserProfileCustomizations.stylesheets", true); // Legacy CSS support
user_pref("ui.prefersReducedMotion", 1); // Disable animations

// // Google Safe Browsing
user_pref("browser.safebrowsing.downloads.enabled", false);
user_pref("browser.safebrowsing.malware.enabled", false);
user_pref("browser.safebrowsing.phishing.enabled", false);
user_pref("browser.safebrowsing.provider.mozilla.gethashURL", "");
user_pref("browser.safebrowsing.provider.mozilla.updateURL", "");

// // Mozilla Blocklist
user_pref("extensions.blocklist.enabled", false); // Disable blocklist
user_pref("extensions.blocklist.url", "");
user_pref("services.settings.server", ""); // Disable contacting settings server

// Custom
user_pref("full-screen-api.ignore-widgets", true);
user_pref("permissions.default.shortcuts", 0);

