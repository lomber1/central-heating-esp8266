const char INDEX_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="UTF-8">
    <title>Piec</title>
    <style>
        body, html {
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
            width: auto;height: auto;margin: 0 auto;text-align: center;background-color: #fff;border-radius: 25px;
            padding: 8px;
        }

        input {
            border-radius: 25px;
            width: 300px;
            height: 40px;
            padding-left: 10px;
            border: 1px solid transparent;
            background-color: #f5f5f5;font-size: 18px;
        }

        input:hover {
            border: 1px solid #29b6f6;
        }

        input[type=submit] {
            background-color: #29b6f6;
        }

        input[type=submit]:hover {
            background-color: #0086c3;
            border: none;
        }
    </style>
</head>
<body>
<div class="container">
    <div class="form-container">
        <form action="/turn-furnace-off" method="POST">
            <input class="formEl" type="password" name="password" placeholder="Hasło: "/><br/>
            <input class="formEl" type="submit" value="Wyłącz piec"/>
        </form>
    </div>
</div>
</body>
</html>

)=====";