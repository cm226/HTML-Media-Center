const express = require('express')
const app = express()
const port = 8000
app.use(express.static('node_modules'))
app.use(express.static('public'))

app.get('/data', (req, res) => {
    res.status(200).send({
        data: {
            temperature: [{
                t: new Date("2015-3-15 13:3"),
                y: 28,
            },
            {
                t: new Date("2015-3-15 18:3"),
                y: 27,
            },
            {
                t: new Date("2015-3-16 13:3"),
                y: 28,
            }],
            gravity: [{
                t: new Date("2015-3-15 13:3"),
                y: 1.037,
            },
            {
                t: new Date("2015-3-15 18:3"),
                y: 1.035,
            },
            {
                t: new Date("2015-3-16 13:3"),
                y: 1.030,
            }],
            alcoholPercentage: 'bop'
        },
    })
});

app.listen(port, () => console.log(`Example listening at http://localhost:${port}`))