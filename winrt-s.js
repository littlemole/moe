Chakra.WinRT("Windows.Foundation");
Chakra.WinRT("Windows.Storage");


function getFile() {

	return new Promise( function(resolve,reject) {

		Windows.Storage.StorageFile.getFileFromPathAsync("C:\\moe\\test.txt")
		.done( 
			function(file) {
				resolve(file);
			},
			function(error) {
				reject(error);
			}		
		);
	});

}

getFile()
.then(

	function(file) {

		Windows.Storage.FileIO.readTextAsync(file)
		.done( function (fileContent) {

				Chakra.MsgBox(fileContent,"TITLE",0);
				Chakra.Quit();
			},
			function (error) {

				Chakra.MsgBox("ERROR","TITLE",0);
				Chakra.Quit();
			}
		);
	},
	function(error) {

		Chakra.MsgBox("ERROR","TITLE",0);
		Chakra.Quit();
	}
);

/*
Windows.Storage.StorageFile.getFileFromPathAsync("C:\\moe\\test.txt")
.then( function(file) {

	return Windows.Storage.FileIO.readTextAsync(file);
})
.done( function (fileContent) {

		Chakra.MsgBox(fileContent,"TITLE",0);
		Chakra.Quit();
	},
	function (error) {

		Chakra.MsgBox("ERROR","TITLE",0);
		Chakra.Quit();
	}
);
*/
Chakra.Wait();