import plotly.plotly as py
import plotly.graph_objs as go
import pandas as pd
import plotly
import sys
import getopt

plotly.tools.set_credentials_file(username='', api_key='')

df = pd.read_csv("./sensordata.csv")

def temperature():

        data = [go.Scatter(x=df.Time,y=df['Temperature'],name ="Temperature")]
	py.iplot(data)

def luminosity():
        data = [go.Scatter(x=df.Time,y=df['Luminosity'])]
        py.iplot(data)

def humidity():
        data = [go.Scatter(x=df.Time,y=df['Humidity'])]
        py.iplot(data)

try:
	opts, args = getopt.getopt(sys.argv[1:], "htl", ["temperature","luminosity" "humidity"])
except getopt.GetoptError:
	sys.exit(2)
for opt, arg in opts:
	if opt in ("-h", "--humidity"):
		humidity()
	elif opt in ("-t", "--temperature"):
		temperature()
	elif opt in ("-l", "--luminosity"):
		luminosity()
