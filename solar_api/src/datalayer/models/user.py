from tortoise.models import Model
from tortoise import fields

class Tournaments(Model):
    id = fields.IntField(primary_key=True)
    name = fields.CharField(max_length=128)
    email = fields.CharField(max_length=128)
    password = fields.CharField(max_length=128)