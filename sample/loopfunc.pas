program main(input);
var
a:integer;
procedure p1(x:integer);
        begin
                if (x<5) then
                        write(x);
        end;
begin
        read(a);
        while a<10 do
        begin
                p1(a);
                a:=a+1
        end;
end.
