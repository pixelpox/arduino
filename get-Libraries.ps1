$arduinoLibraries = "C:\Users\simon\arduino\libraries"

$libraries = [
	"https://github.com/knolleary/pubsubclient/archive/master.zip" #MQTT
]

$client = new-object System.Net.WebClient
$client.DownloadFile("https://github.com/knolleary/pubsubclient/archive/master.zip","C:\Users\simon\arduino\libraries\master.zip")

Expand-Archive -LiteralPath C:\Users\simon\arduino\libraries\master.zip