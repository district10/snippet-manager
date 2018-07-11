// c++ system command
char buffer[2048];
sprintf(buffer, "python " PROJECT_SOURCE_DIR "/script.py %s %s", output_me.c_str(), input_me.c_str());
cout << "cmd: " << buffer << endl;
int ret = system(buffer);
