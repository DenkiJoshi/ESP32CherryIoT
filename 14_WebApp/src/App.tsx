import React, { useState } from 'react';
import './App.css';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <MakeButton />
      </header>
    </div>
  );
}

function MakeButton() {
  const [array, setArray] = useState([0, 1, 2]);
  const buttonClick = (i: number) => {
    const newArray = array.concat();// 配列のコピー
    newArray[i]++;
    setArray(newArray);
    // 更新されないダメな例↓
    // array[i]++;
    // setArray(array);
  };
  return (<div>
    {array.map((x, i) =>
      <button key={i} onClick={() => buttonClick(i)}>{x}</button>
    )}
  </div>);
}
export default App;

