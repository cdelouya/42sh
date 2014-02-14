edit line commands:

         right  >  next char
          left  >  previous char
  ctrl + right  >  next word
   ctrl + left  >  previous word
     ctrl + up  >  move up
   ctrl + down  >  move_down
      ctrl + a  >  move to begin
      ctrl + e  >  move to end
      ctrl + w  >  copy
      ctrl + x  >  paste
       alt + w  >  cut
            up  >  previous command
          down  >  next command
        ctrl_d  >  terminate line with nul character

builtins:

           env  >  show environement
        setenv  >  set environement variable
      unsetenv  >  unset environement variable
            cd  >  change directory
          exit  > terminate process
            fg  >  resume process  //// NOTE: (fg [number of suspended job])
          jobs  > show list of suspended jobs
          echo  > write in stdout

signals:

        ctrl_c  > terminate process
        ctrl_z  > Suspend job (and add to list)

redirections:

  >: clear file and write the output in file. (file is create if didn't exist)
  >>: write the output at the end of file. (file is create if didn't exist)
  <: read source from file
  <<: read source from stdin while the 'END' string not found
  |: send output of cmd1 to source of cmd 2

             +++++ INFOS +++++

-> you can write command without spaces around operators.
		ex: ls|cat -e;echo ">>\";|"
-> alias are replaced
-> ~ is replaced
-> * are replaced
-> environement variables are replaced
-> verifying permission for complete path (dir by dir)

			+++++ FIXES +++++

-> history crash fixed
-> argument split fixed (don't split quoted strings)
