program main(input);
    procedure p1;
    begin
        write(1);
    end;
    procedure p2;
        procedure p3;
        begin
            write(3);
        end;
    begin
        write(2);
        p3;
    end;
begin
    write(0);
    p1;
    p2;
end.
