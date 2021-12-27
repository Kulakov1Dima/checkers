import uvicorn
import asyncio
from fastapi import Body, FastAPI

app = FastAPI()

@app.post("/")
async def read_root(request = Body(..., embed=True)):
    results = {
        "response": {
            "text":request['command']
            },
            "version": "1.0"
        }
    return results 

if __name__ == "__main__":
    uvicorn.run("main:app", host="localhost", port=8010, reload=True)