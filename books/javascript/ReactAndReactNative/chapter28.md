## 28 Going Offline
- Detecting the state of the network
	- Let’s look at some code that uses the NetInfo utility from the `@react-native-community/netinfo`
package to handle changes in network state:

			const connectedMap = {
			 none: "Disconnected",
			 unknown: "Disconnected",
			 cellular: "Connected",
			 wifi: "Connected",
			 bluetooth: "Connected",
			 ethernet: "Connected",
			 wimax: "Connected",
			 vpn: "Connected",
			 other: "Connected",
			} as const;
- Storing application data
	- To store data on the device, there is a special cross-platform solution called AsyncStorage API. It works the same on both the iOS and Android platforms. You would use this API for applications that don’t require any network connectivity in the first place or to store data that will eventually be synchronized using an API endpoint once a network becomes available.
	- To install the async-storage package, run the following command:

			npx expo install @react-native-async-storage/async-storage
- Synchronizing application data
	- The basic idea is to only make network requests when you know for sure that the device is online. If you know that it isn’t, you can store any changes in the state locally. Then, when you’re back online, you can synchronize those stored changes with the remote API.