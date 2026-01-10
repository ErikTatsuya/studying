import subprocess
from flask import Flask, jsonify

app = Flask(__name__)

id_counter_c = 0
id_counter = 0

@app.route("/pow/<int:base>/<float:power>", methods=["GET"])
def pow(base, power):
    global id_counter
    numbers = []
    for i in range(int(power) + 1):
        numbers.append(base ^ i)

    id_counter += 1
    return jsonify({
        "base": str(base),
        "power": str(power),
        "status": "200",
        "id_counter": id_counter,
        "results": numbers
    })

@app.route("/pow_c/<int:base>/<float:power>", methods=["GET"])
def pow_c(base, power):
    global id_counter_c
    result = execute_pow_function(base, power)

    numbers_string = result.strip("\n").split()
    numbers = []

    for i in numbers_string:
        num = float(i)
        numbers.append(num)

    id_counter_c += 1
    return jsonify({
        "base": str(base),
        "power": str(power),
        "status": "200",
        "id_counter_c": id_counter_c,
        "results": numbers
    })
    

def execute_pow_function(base, power):
    executable_path = "./argumentos_linha_de_comando.out"

    base = str(base)
    power = str(power)

    result = subprocess.run(
        [executable_path, base, power],
        capture_output=True,
        text=True
    )
    if result.returncode == 0:
        return result.stdout
    
    print(f"error, {result.stderr}")
    return 1
    
if __name__ == "__main__":
    #execute_pow_function(10, 3)
    app.run(debug=True, port=8080)


