import json
from fastapi import Body, FastAPI

app = FastAPI()

@app.post("/")
def read_root(request = Body(..., embed=True)):
    data = json.loads(json.dumps(request))
    results = {
        "response": {
            "text":data['command']
            },
            "version": "1.0"
        }
    return results 