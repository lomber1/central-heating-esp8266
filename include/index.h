const char INDEX_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="UTF-8">
    <title>Piec</title>
    <style>
        body,
        html {
            margin: 0;
            height: 100%;
        }

        body {
            background-color: #29b6f6;
        }

        .container {
            width: 100%;
            height: 100%;
            margin-left: auto;
            box-sizing: border-box;
            margin-right: auto;
            padding-left: 16px;
            padding-right: 16px;
            display: flex;
            align-items: center;
            justify-content: center;
        }

        @media only screen and (max-width: 600px) {
            .container {
                padding-left: 24px;
                padding-right: 24px;
            }
        }

        .formEl {
            margin: 8px;
            box-sizing: border-box;
        }

        .form-container {
            width: auto;
            height: auto;
            margin: 0 auto;
            text-align: center;
            background-color: #fff;
            border-radius: 25px;
            padding: 8px;
        }

        .hidden {
            display: none;
        }

        #submitButton {
            border-radius: 25px;
            width: 300px;
            height: 40px;
            padding-left: 10px;
            border: 1px solid transparent;
            background-color: #f5f5f5;
            font-size: 18px;
            background-color: #29b6f6;
        }

        #submitButton:hover {
            border: 1px solid #29b6f6;
            background-color: #0086c3;
        }
    </style>
</head>

<body>
    <div class="container">
        <div class="form-container">
            <h4 class="hidden" id="turn-off-status">Wyłączony</h5>
            <h5 class="hidden" id="turn-off-error">Jakiś błąd, nie wiem głupi hjestem</h5>
            <button class="formEl" id="submitButton" value="Wyłącz piec" onclick="turnOffFurnace()">Wyłącz piec</button>
        </div>
    </div>
    <script>
        function show(id) {
            document.getElementById(id).classList.remove('hidden');
        }

        function turnOffFurnace() {
            fetch("http://192.168.1.69/turn-furnace-off", {
                method: "POST"
            })
                .then((response) => show("turn-off-status"))
                .catch((err) => {
                    show('turn-off-error');
                    console.error(err);
                });
        }
    </script>
</body>

</html 

)=====";