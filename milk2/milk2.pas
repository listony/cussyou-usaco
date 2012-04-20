{
ID: cussyou1
PROG: milk2
LANG: PASCAL
}
{ milk2.pas -- by lizhonglei 2009-06-28 }

program milk2(input,output);
{$APPTYPE CONSOLE}
var
   line	   : array [0..1000000] of char;
   maxNum  : longint; { the max number in line }
   maxBoys : longint; { how many are there milking }
   maxFree : longint; { max seconds of free time }
   maxWork : longint; { max seconds of work time }
   i	   : longint;
   time1   : longint;
   time2   : longint;
   ind1	   : longint;
   ind2	   : longint;
procedure paintLine(t1: longint; t2 : longint);
var
   i : longint;
begin
   for i:=t1 to t2-1 do
      line[i]:='a';
end;
begin
   assign(input,'milk2.in');
   assign(output,'milk2.out');
   reset(input);
   rewrite(output);
   { init }
   for i:=0 to 1000000 do
      line[i]:='0';
   { read all }
   readln(maxBoys);
   maxNum:=0;
   for i:= 1 to maxBoys do
   begin
      readln(time1,time2);
      paintLine(time1,time2);
      if time2>maxNum then maxNum:=time2;
   end;
   { find first segment }
   ind1:=0;
   maxWork:=0;
   maxFree:=0;
   for i:=0 to maxNum do
      if line[i]='a' then
      begin
	      ind1:=i;
	      break;
      end;
   
   for i:=ind1 to maxNum-1 do
   begin
      if line[i]<>line[i+1] then 
      begin
	 ind2:=i+1;
	 if line[i]='a' then { doing work }
	 begin
	    if ind2-ind1 > maxWork then
	       maxWork:=ind2-ind1;
	 end
	 else if line[i]='0' then {free time}
	 begin
	    if ind2-ind1 > maxFree then
	       maxFree:=ind2-ind1;
	 end;
	 ind1:=ind2; { move index forward }
      end;
   end;
   { output }
   writeln(maxWork,' ',maxFree);
   close(input);
   close(output);
end.

