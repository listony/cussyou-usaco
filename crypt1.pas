{
ID: cussyou1
PROG: crypt1
LANG: PASCAL
}
Program crypt1;
const
  inf='crypt1.in';
  ouf='crypt1.out';
  maxn=10;
var
  i,j,k,n,i2,j2,numi,numj,num1,tem1,tem2,tot:longint;
  ys:array[0..9]of boolean;
Procedure init;
Begin
  readln(n);
  fillchar(ys,sizeof(ys),false);
  for i:=1 to n do
    begin
      read(k);
      ys[k]:=true;
    end;
End;
Function pd(a:longint):boolean;
var
  i,j,k:longint;
Begin
  pd:=false;
  while a>0 do
  begin
    i:=a mod 10;
    a:=a div 10;
    if not ys[i]then exit;
  end;pd:=true;
End;
BEGIN
  assign(input,inf);
  assign(output,ouf);
  reset(input);
  rewrite(output);
  init;tot:=0;
  for i:=1 to 9 do
    if ys[i] then
    begin
      numi:=i*100;
      for j:=0 to 9 do
        if ys[j]then
        begin
          numj:=j*10;
          for k:=0 to 9 do
           if ys[k]then
           begin
             num1:=numi+numj+k;
             for i2:=1 to 9 do
              if ys[i2]then
              begin
                tem1:=i2*num1;
                if tem1>999 then continue;
                if not pd(tem1)then continue;
                for j2:=1 to 9 do
                 if ys[j2]then
                 begin
                   tem2:=j2*num1;
                   if tem2>999 then continue;
                   if not pd(tem2)then continue;
                   if tem1*10+tem2<999 then continue;
                   if tem1*10+tem2>9999 then continue;
                   if not pd(tem1*10+tem2)then continue;
                   inc(tot);
                 end;
                end;
              end;
             end;
           end;
          writeln(tot);
          close(input);
          close(output);
END.
