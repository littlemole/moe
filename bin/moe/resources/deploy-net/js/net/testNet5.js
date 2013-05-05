var net = new NET();

var System = net.Import("System");
net.Import("System.Net");

var webClient = new System.Net.WebClient();
webClient.Encoding = System.Text.Encoding.UTF8;

var uri = new System.Uri("http://www.heise.de/");
var result = webClient.DownloadString(uri);

var doc = moe.Documents.New();
doc.Object.Properties.Encoding = moe.UTF8; // UTF-8
doc.Object.Text = result;

net.Exit();