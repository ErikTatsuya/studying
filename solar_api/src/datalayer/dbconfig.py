from tortoise.contrib.fastapi import register_tortoise
from fastapi import FastAPI


def config_db(app: FastAPI): 
    register_tortoise(
        app = app,

        config = {
            "connections" : {
                # "default" : "postgres://postgres:qwerty123@localhost:5432/events"
                "default" : "sqlite://db.sqlite3"
            },
            "apps" : {
                "models": {
                    "models": [
                        "src.datalayer.models.user"
                    ]
                }
            }
        },

        generate_schemas=True,
        add_exception_handlers=True,
    )