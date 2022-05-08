program main(input, out,put);
var
numbers:array [1..5] of integer;
i:integer;
begin
    i:=1;
    while i<=5 do
    begin
        numbers[i]:=5-i;
        i:=i+1;
    end;
    i:=1;
    while i<=5 do
    begin
        write(numbers[i]);
        i:=i+1;
    end;
end.