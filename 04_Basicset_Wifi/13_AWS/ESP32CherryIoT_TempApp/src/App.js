import React, { useEffect, useState } from 'react';
import { LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, ResponsiveContainer } from 'recharts';

const API_URL = "https://xxxxxxxx.execute-api.ap-northeast-1.amazonaws.com/prod/devices/ESP32CherryIoT_Device001";

function App() {
  const [data, setData] = useState([]);

  useEffect(() => {
    fetch(API_URL)
      .then((res) => res.json())
      .then((result) => {
        const formatted = result.Items.map(item => ({
          timestamp: item.timestamp || "not clear",
          temperature: parseFloat(item.temperature)
        }));
        setData(formatted.reverse());
      })
      .catch((err) => {
        console.error("Data Get Error:", err);
      });
  }, []);

  return (
    <div style={{ padding: "2rem", fontFamily: "sans-serif" }}>
      <h2>📊ESP32CherryIoT TempApp</h2>
      <ResponsiveContainer width="100%" height={400}>
        <LineChart data={data}>
          <CartesianGrid stroke="#eee" strokeDasharray="5 5" />
          <XAxis dataKey="timestamp" tick={{ fontSize: 12 }} />
          <YAxis unit="℃" domain={['auto', 'auto']} />
          <Tooltip />
          <Line type="monotone" dataKey="temperature" stroke="#8884d8" strokeWidth={2} />
        </LineChart>
      </ResponsiveContainer>
    </div>
  );
}

export default App;
