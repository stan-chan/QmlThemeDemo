import QtQuick
import QtQuick.Controls
import XmlHelper 1.0
import "./Themes"

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

    XmlHelper{
        id:xmlID
        ip:"12"
    }

    Button{
        width:100
        height:30
        x:300;y:50
        text: xmlID.ip
        onClicked: {
            xmlID.readXml();
            if(ThemeManager.theme == OneDark)
            {
                ThemeManager.theme = Light;
            }
            else if(ThemeManager.theme == Light)
            {
                ThemeManager.theme = OneDark;
            }
        }
    }
}
