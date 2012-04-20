{
ID:cussyou1
PROG:contact
LANG:PASCAL
}
program JAckchen;
var a,b,n,n1:longint;
     s:array[1..200000] of integer;
     f:array[1..12,0..4096] of longint;
     ans:array[1..200000,1..2] of longint;
     i,j,k,x,y,c,d,pre:longint;
     ch:char;
  procedure print(p,q:longint);
  var tmp:array[1..12] of integer;
       i1,j1,m:integer;
  begin
     m:=p; j1:=0;
     fillchar(tmp,sizeof(tmp),0);
     repeat
       inc(j1);
       tmp[j1]:=m mod 2;
       m:=m div 2;
     until m=0;
     for i1:=q downto 1 do
       write(tmp[i1]);
  end;

begin
  assign(input,'contact.in'); assign(output,'contact.out');
  reset(input); rewrite(output);
  readln(a,b,n); n1:=0;
  while not eof do
      begin
        read(ch);
        if ch in ['0'..'1']  then
        begin
        inc(n1);
        s[n1]:=ord(ch)-48;
        end;
      end;
  fillchar(f,sizeof(f),0);
  for i:=1 to n1 do
  begin
     x:=0; y:=1;
     for j:=1 to b do
     if i-j+1>=1 then
     begin
       x:=x+y*s[i-j+1]; y:=y*2;
       if (j<=b)and(j>=a) then
         inc(f[j,x]);
     end;
  end;
  pre:=maxlongint;
  for i:=1 to n do
  begin
     c:=0; d:=0;
     for j:=a to b do
     for k:=0 to 4096 do
       if (f[j,k]>c)and(f[j,k]<pre) then
         begin
           d:=1;
           ans[d,1]:=k; ans[d,2]:=j;
           c:=f[j,k];
         end
       else
       if (f[j,k]=c)and(f[j,k]<pre)and(c<>0) then
         begin
           inc(d);
           ans[d,1]:=k; ans[d,2]:=j;
         end;
     pre:=c;
     if c<>0 then writeln(c);
     for j:=1 to d do
       begin
         print(ans[j,1],ans[j,2]);
         if j mod 6=0 then writeln
         else
         if j<>d then write(' ')
         else writeln;
       end;
  end;
  close(input); close(output);
end.

