import plotly.express as px
import pandas as pd

country=input("Enter the country name : ")

data = {
    "country": [country],
    "value": [100]
}
df = pd.DataFrame(data)

fig = px.choropleth(
    df,
    locations="country",
    locationmode="country names",
    color="value",
    title="Example Choropleth Map"
)
fig.show()
