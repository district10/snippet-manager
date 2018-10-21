from pathlib import Path

# os.path.join
directory = Path("/etc")
filepath = directory / "hosts"

if filepath.exists():
    print('hosts exist')
