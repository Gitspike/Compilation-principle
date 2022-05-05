program main(input);
var
c:array [1..3, 1..4, 1..5] of integer;
begin
	c[1][2][3]:=1;
	writeln(c[1][2][3]);
end.

