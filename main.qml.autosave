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
        width:100
        height:30
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
