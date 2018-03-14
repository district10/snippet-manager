lsof -i :8080  | awk '{print $2}' | tail -n 1 | xargs kill # kill port
