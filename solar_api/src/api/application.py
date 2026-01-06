from fastapi import FastAPI
from src.datalayer.dbconfig import config_db

def create_app():
    app = FastAPI()

    # inicializar db/tortoise
    config_db(app)

    return app    

app = create_app()

@app.get("/")
async def home():
    return {
        "status": 200,
        "message": "ok"
    }