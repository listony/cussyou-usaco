{
ID: cussyou1
PROGR: transform
LANG: PASCAL
}
{ transform.pas -- by lizhonglei 2009-06-28 }

program transform(input,output);
{$APPTYPE CONSOLE}
type
   bm =  array [1..10,1..10] of char;
var
   matrix : bm;
   tmpMatrix	  : bm;
   size	  : integer;
   i,j	  : integer;
   method : integer;
function isEqual :boolean;
var
   i,j : integer;
begin
   result:=true;
   for i:=1 to size do
      for j:=1 to size do
	 if tmpMatrix[i,j] <> matrix[i,j] then
	 begin
	    result:=false;
	    break;
	 end;
end;
procedure rotate90;
var
   i,j : integer;
begin
   for i:=1 to size do
      for j:=1 to size do
	 tmpMatrix[j,size+1-i]:=matrix[i,j];
end; { rotate90 }
procedure rotate180;
var
   i,j : integer;
begin
   for i:=1 to size do
      for j:=1 to size do
	 tmpMatrix[size+1-i,size+1-j]:=matrix[i,j];
end; { rotate180 }
procedure rotate270;
var
   i,j : integer;
begin
   for i:=1 to size do
      for j:=1 to size do
	 tmpMatrix[size+1-j,i]:=matrix[i,j];
end; { rotate270 }
procedure reflact;
var
   i,j : integer;
begin
   for i:=1 to size do
      for j:=1 to size do
	 tmpMatrix[i,size+1-j]:=matrix[i,j];
end; { reflact }

begin
   { init }
   for i:=1 to size do
      for j:=1 to size do
      begin
	 matrix[i,j]:='0';
	 tmpMatrix[i,j]:='0';
      end;
   { read all }
   readln(size);
   for i:=1 to size do
      for j:=1 to size do
	 read(matrix[i,j]);
   { work }
   method:=7;
   for i:=1 to 7 do
   begin
      case i of
	1 : begin
	       rotate90;
	    end;
	2 : begin
	       rotate180;
	    end;
	3 : begin
	       rotate270;
	    end;
	4 : begin
	       reflact;
	    end;
	5 : begin
	       reflact;
	       rotate90;
	       if isEqual then
	       begin
		  method:=5;
		  break;
	       end;
	       rotate180;
	       if isEqual  then
	       begin
		  method:=5;
		  break;
	       end;
	       rotate270;
	       if isEqual  then
	       begin
		  method:=5;
		  break;
	       end;
	    end;
	6 : begin
	    end;
	7 : begin
	    end;	
      end; { case }
      if isEqual then
      begin
	 method:=i;
	 break;
      end;
   end;
   writeln(method);
end.


