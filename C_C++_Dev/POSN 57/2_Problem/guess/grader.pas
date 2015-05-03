program grader;
   uses gradershare, player;
   var r: longint;
begin
   read(N,secret);
   r := play(N);
   if r = secret then
      Writeln ('Correct ',r)
   else
      Writeln ('Incorrect ',r,' should be ',secret);
end.
