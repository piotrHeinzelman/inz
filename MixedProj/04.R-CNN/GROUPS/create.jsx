

var folder = new Folder("C:\\Users\\PiotrH\\Desktop\\IMG_SAS\\GROUPS\\");
var allFiles = folder.getFiles("*.txt");
var out = new File ( "C:\\Users\\PiotrH\\Desktop\\IMG_SAS\\GROUPS\\out.data" );
out.open("W");


for ( var i=0;i<allFiles.length;i++){
    funFiles( allFiles[i] , out );
}

out.close();

function funFiles( file, out ){
    file.open("R");
    var row = file.readln();
           row = file.readln();
    var ary=row.split(",");
    for (j=0;j<4;j++){
    ary[j]= Math.round(17.7165*ary[j]);
    }    
    file.close();
    var s=file.name.replace(".txt",".jpg") + "\t[" + ary.join(",")+"]" ;
    out.writeln( s  );   
   
}