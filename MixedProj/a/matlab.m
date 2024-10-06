cycles=1000;
name="20";


%generate data
if (false)
    x=[ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]

    fileID=fopen( append ('data\datax',name,'.bin'),'w');
    fwrite( fileID, x, 'double' );
    fclose(fileID);

    y=[ -1.69 -0.79 5.77 7.80 4.56 14.32 15.47 8.88 7.41 17.26 14.83 20.47 20.39 27.04 22.53 22.36 29.35 22.86 31.22 28.13 ]

    fileID=fopen(append('data\datay',name,'.bin'),'w');
    fwrite( fileID, y, 'double' );
    fclose(fileID);
end


%load data
if (true)
    fileID=fopen(append('data/datax',name,'.bin'),'r');
    x=fread( fileID, 'double' );
    fclose(fileID);

    fileID=fopen(append('data/datay',name,'.bin'),'r');
    y=fread( fileID, 'double' );
    fclose(fileID);
end


ST = datetime('now');
for i = 1:cycles
    a = polyfit(x,y,1);
end

ED = datetime('now');

D = duration( ED-ST );
L = size( x );

fprintf('# Polyfit:  X[%i] * cycles: %i \n', L(1), cycles  );
fprintf( '# result: a:%f, a:%f\n\n' , a(2), a(1) );
fprintf ('y[2]=%f\n' , seconds(D)  );


ST2 = datetime('now');

xsr = 0;
ysr = 0;
w0  = 0;
w1  = 0;

for c = 1:cycles
   xsr = 0;
   ysr = 0;
   for i=1:length(x)
      xsr = (x(i)+xsr);
      ysr = (y(i)+ysr);
   end

   xsr = xsr/length(x);
   ysr = ysr/length(x);

   w0=0;
   w1=0;
   sumTop=0;
   sumBottom=0;

   for i = 1:length(x)
      sumTop     = ((( x(i)-xsr ) * ( y(i)-ysr )) + sumTop);
      sumBottom  = ((( x(i)-xsr ) * ( x(i)-xsr )) + sumBottom);


   end
   w1 = sumTop/sumBottom;
   w0 = ysr-( w1 * xsr );      

end

ED2 = datetime('now');
D2 = duration( ED2-ST2 );

fprintf('# implemented:  X[%i] * cycles: %i \n', L(1), cycles  );
fprintf('# result: w0:%f, w1:%f\n\n', w0, w1);
fprintf ('y[3]=%f\n' , seconds(D2)  );

