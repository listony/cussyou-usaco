{
ID: cussyou1
PROG: milk2
LANG: PASCAL
}
{ milk22.pas -- by lizhonglei 2009-06-28 }
program milk2 (input,output);
type
   link	 = ^point;
   point = record
	      time    : longint;
	      isStart : boolean; {1 start,0 ,-1 stop }
	   end;	      
   
var
   time1   : longint;
   time2   : longint;
   maxBoys : longint;
   maxWork : longint;
   maxFree : longint;
   i	   : longint;
   line	   : array of point;
   isWork  : boolean;
procedure msort;
var
   i,j,k : integer;
   tmp	 : longint;
   tmpP	 : point;
begin
   for i:= 2*maxBoys-1 downto 0 do
   begin
      tmp:=0;
      k:=0;
      for j:= i downto 0 do
      begin
	 if line[j].time>tmp then
	 begin
	    tmp:=line[j].time;
	    k=j;
	 end;
      end;
      { exchange }
      tmpP:=line[k];
      line[k]:=line[j];
      line[j]:=tmpP;
   end;
end;
begin
   readln(maxBoys);
   setLength(line,2*maxBoys);
   for i:=0 to maxBoys-1 do
   begin
      readln(line[2*i].time,line[2*i+1].time);
      line[2*i].isStart:=true;
      line[2*i+1].isStart:=false;
   end;
   { sort }
   msort;
   { delete some }
   { find max }
   time1:=line[0].time;
   isWork:=true;
   for i:=0 to 2*maxBoys-1 do
   { out }
   writeln(maxWork,' ',maxFree);
end.


	   .