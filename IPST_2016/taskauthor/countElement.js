console.log("File : " + process.argv[2]);

const fs = require('fs');

fs.readFile(process.argv[2], 'ascii', (err,data) => {
	if(err){
		if(err.code=='ENOENT') console.log('No valid file');
		else console.log(err);
	}else{
		console.log("X/T : " + data.replace( /\n/g, " " ).trim().split(/\s+/).length + "/" + process.argv[3]);
	}
});