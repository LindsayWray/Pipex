## Objective 

  Reproduce the shell's pipe and redirections (<, >, << and >>).
  

  ### Example:
  
	./pipex infile "grep a1" "wc -w" outfile

  ### Should behave like:

	< infile grep a1 | wc -w > outfile
