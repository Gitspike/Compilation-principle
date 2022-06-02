program main(input);
var
ret:integer;
function f1(x:integer):integer;
	var
	num:integer;
	begin
		{write(x);}
		read(num);
		while num < x do
		begin
			write(num);
			num := num + 1
		end;
		f1:=1;
	end;
begin
	ret:=f1(3);
	write(ret);
end.
