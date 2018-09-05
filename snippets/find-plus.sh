find . -exec ls {} +

-exec command ;
    Execute command; true if 0 status is returned. All following arguments to
    find are taken to be arguments to the command until an argument consisting
    of ';' is encountered. The string '{}' is replaced by the current file name
    being processed everywhere it occurs in the arguments to the command, not
    just in arguments where it is alone, as in some versions of find. Both of
    these constructions might need to be escaped (with a '\') or quoted to
    protect them from expansion by the shell. See the EXAMPLES sec- tion for
    examples of the use of the '-exec' option. The speci- fied command is run
    once for each matched file. The command is executed in the starting
    directory. There are unavoidable security problems surrounding use of the
    -exec option; you should use the -execdir option instead.

-exec command {} +
    This variant of the -exec option runs the specified command on the selected
    files, but the command line is built by appending each selected file name
    at the end; the total number of invoca- tions of the command will be much
    less than the number of matched files. The command line is built in much
    the same way that xargs builds its command lines. Only one instance of '{}'
    is allowed within the command. The command is executed in the starting
    directory.
