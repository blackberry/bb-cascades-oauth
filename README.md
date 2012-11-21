About the oauth library for BlackBerry 10
==========================================
This is a OAuth library built for the Cascades development framework for BlackBerry 10. It is a fork and BlackBerry specific implementation of the KQOauth library that can be found here http://www.gitorious.org/kqoauth under the LGPL license.

This library supports both OAuth1 and OAuth2 authorization flow and authorized requests.
For authentication, both XAuth and the normal Token flow are supported. If using the token flow, your api provider must support a callback url so the library can process the auth. It uses the native BlackBerry browser for authentication and handles callbacks from there via http://localhost.

You will be able to provide a local html file that shows to the user in your webview after they successfully authorize your app.

Stay tuned for examples on each method coming soon.
