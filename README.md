# QmlThemeDemo
# QML动态换肤（CMake）

代码放入github供以后参考

1. 更改CMakeLists.txt，使CMake可批量添加.cpp、.h、.qml文件
  
2. 在CMakeLists.txt同级目录中，创建Resources文件夹
  
3. 在Resources文件夹中，创建Themes文件夹
  
4. 创建主题相关文件ThemeBase.qml、ThemeManager.qml、Light.qml、Dark.qml、OneDark.qml
  
5. 新建Qt Resource File，命名为Resource.qrc，放在CMakeLists.txt同级目录中（Resources文件夹之外）
  
6. 将主题相关文件添加到Resources.qrc中
  
7. 新建Empty File，命名为qmldir，放在和主题文件同级目录中
  
8. 各文件内容如下
  
  ThemeBase.qml
  
  ```qml
  import QtQuick
  QtObject{
      property color foreground: "#FFFFFF"
      property color background: "skyblue"
  }
  ```
  
  ThemeManager.qml
  
  ```qml
  pragma Singleton
  import QtQuick
  QtObject {
      property ThemeBase theme: Light
  }
  ```
  
  Light.qml
  
  ```qml
  pragma Singleton
  import QtQuick
  ThemeBase {
      foreground: "#000000"
      background: "#1296db"
  }
  ```
  
  Dark.qml
  
  ```qml
  pragma Singleton
  import QtQuick
  QtObject {
      property color background: "red"
      property color foreground:"blue"
  }
  ```
  
  OneDark.qml
  
  ```qml
  pragma Singleton
  import QtQuick
  ThemeBase {
      foreground: "red"
      background: "#FFFFFF"
  }
  ```
  
  qmldir
  
  ```
  module Resources.Themes
  ThemeBase 1.0 qrc:/Resources/Themes/ThemeBase.qml
  singleton Dark 1.0 qrc:/Resources/Themes/Dark.qml
  singleton Light 1.0 qrc:/Resources/Themes/Light.qml
  singleton OneDark 1.0 qrc:/Resources/Themes/OneDark.qml
  singleton ThemeManager 1.0 qrc:/Resources/Themes/ThemeManager.qml
  ```
  
  注意事项：
  
  这里需要着重注意module命名，必须与路径命名一致，且要与ImportPath配合使用
  
  main.cpp中需添加，否则会报错module "Resouces.Themes" is not installed
  
  ```cpp
  //如果qmldir中module命名为Resources.Themes，则ImportPath为
  engine.addImportPath("qrc:/");
  //如果qmldir中module命名为Themes,则ImportPath为
  engine.addImportPath("qrc:/Resources");
  ```
  
9. main.qml中进行测试
  
  ```qml
  import QtQuick
  import QtQuick.Controls
  import Resources.Themes 1.0
  Window {
      width: 640
      height: 480
      visible: true
      title: qsTr("Hello World")
  
      Rectangle{
          width:200;height:200
          x:50;y:50
          border.width: 30
          border.color: ThemeManager.theme.foreground
          color:ThemeManager.theme.background
      }
  
      Button{
          width:100;height:30
          x:300;y:50
          text: qsTr("Switch")
          onClicked: {
              if(ThemeManager.theme === OneDark)
              {
                  ThemeManager.theme = Light;
              }
              else if(ThemeManager.theme === Light)
              {
                  ThemeManager.theme = OneDark;
              }
          }
      }
  }
  ```
  

#### 问题点

1. import自定义模块时，会提示QML module not found (Resources.Themes).
  
2. 使用自定义模块时，无法高亮提示
