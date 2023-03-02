TESTER = document.getElementById('tester');
array_x = [1, 2, 3, 4, 5];
array_y = [1, 2, 4, 8, 16];
/*
if data recieved push data into x and y respectively */
Plotly.plot( TESTER, [{
    x: array_x,
    y: array_y }], { 
    margin: { t: 0 } }, {showSendToCloud:true} );


/* Current Plotly.js version */
console.log( Plotly.BUILD );
/* create arrays and replace with above graphs8*/
