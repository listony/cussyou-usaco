{
}
program calfflac (input,output);
{$APPTYPE CONSOLE}

type 
	palnNode = record
		sindx: integer;
		eindx: integer; 
	end;

var
	{ the orignal text }
	textArray : array [1..20000] of char;
	textSize : integer;
	{ the text only a-z A-Z }
	charArray : array [1..20000] of char;
	charPstn : array [1..20000] of integer;
	charSize : integer;
	tmp : char;
	tmpNode : palnNode;
	palnArray : array[1..20000] of palnNode;
	palnSize : integer;
	i : integer;
	max : integer;
	maxIndx : integer;
function compPaln( a: palnNode; b: palnNode) :boolean;
var 
	i: integer;
	d: integer;
begin
	compPaln:=true;
	if a.eindx-a.sindx <> b.eindx-b.sindx then
		compPaln:=false
	else
		begin
			d:= b.sindx-a.sindx;
			for i:=a.sindx to a.eindx do
				if charArray[i] <> charArray[i+d] then
					begin
						compPaln:=false;
						break;
					end;
		end;
end;
begin
	assign(input,'calfflac.in');
	assign(output,'calfflac.out');
	reset(input);
	rewrite(output);
	{ read }
	textSize:=0;
	charSize:=0;
	while not eof(input) do
	begin
		read(tmp);
		textArray[textSize]:=tmp;
		if ((tmp>='a')and(tmp<='z')) or ((tmp>='A')and(tmp<='Z')) then
			begin
				charArray[charSize+1]:=tmp;
				charPstn[charSize+1]:=textSize;{ save the position of this char }
				inc(charSize);
			end;
		inc(textSize);
	end;
	{ init the palnArray }
	for i:=1 to charSize do 
		begin
			palnArray[i].sindx:=0;
			palnArray[i].eindx:=0;
		end;
	{ ok let's go }
	palnSize:=1;
	tmpNode.sindx:=1;
	tmpNode.eindx:=1;
	palnArray[1]:=tmpNode;
	for i:=2 to charSize do
		begin
			tmpNode.sindx:=i;
			tmpNode.eindx:=i;
			if compPaln(tmpNode,palnArray[palnSize]) then { find a palindrom }
				palnArray[palnSize].eindx:=tmpNode.eindx { add to one palindrom }
			else if palnSize>2 then 
				if compPaln(tmpNode,palnArray[palnSize-1]) then { find a palindrom }
				begin
					dec(palnSize);
					palnArray[palnSize].eindx:=tmpNode.eindx;
				end
			else
				inc(palnSize);
		end;	
	{ find max }
	max:=0;
	for i:=1 to palnSize do
		if palnArray[i].eindx-palnArray[i].sindx > max then 
		begin
			max:= palnArray[i].eindx-palnArray[i].sindx ;
			maxIndx := i
		end;
	writeln(max);
	for i:=charPstn[palnArray[maxIndx].sindx] to charPstn[palnArray[maxIndx].eindx] do 
		write(textArray[i]);
	writeln;
	close(input);
	close(output);
end.
