## 22 Collecting User Input
- In web apps, there is a special `<input>` HTML element that allows you to collect user inputs. In React Native, for that purpose, we use the `TextInput` component.
- In web applications, you typically use the `<select>` element to let the user choose from a list of options. React Native comes with a `Picker` component, which works on both iOS and Android, but in terms of reducing the React Native app size, the Meta team decided to delete it in future releases and extract Picker to its own package.
- Another common element you’ll see in web forms is checkboxes. For example, think of toggling Wi-Fi or Bluetooth on your device. React Native has a `Switch` component that works on both iOS and Android.
- .React Native docs suggest using `@react-native-community/datetimepicker` independent `date/time picker` 
components for iOS and Android, which means that it is up to you to handle the cross-platform differences between the components.