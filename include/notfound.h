const char NOTFOUND_page[] PROGMEM = R"=====(
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
    </style>
</head>
<body>
<div class="container">
    <h1>404: NotFound</h1>
</div>
</body>
</html>

)=====";