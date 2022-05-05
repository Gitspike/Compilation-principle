program main(input);
var
	a,b:integer;

procedure exchange(var x:integer; var y:integer);
	var
		z:integer;
	begin
		z:=x;
		x:=y;
		y:=z;
	end;

begin
	a:=1;
	read(a);
	b:=2;
	write(a);
	write(b);
	exchange(a,b);
	write(a);
	write(b);
end.

