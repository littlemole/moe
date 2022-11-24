Chakra.WinRT("Windows.Foundation");
var wrtStorage = Chakra.WinRT("Windows.Storage");


async function getFile() {

	try {

		var file = await wrtStorage.StorageFile.getFileFromPathAsync("C:\\moe\\test.txt");
		var fileContent = await wrtStorage.FileIO.readTextAsync(file);

		MsgBox(fileContent,"TITLE",0);
		Quit();
	}
	catch(error)
	{
		MsgBox(error,"ERROR",0);
		Quit();
	}
}

getFile();
Wait();