function makeFancyString(s: string): string {
    
     let result = s.split("");

  for (let i = 0; i < result.length; i++) {
    if (result[i] == result[i + 1] && result[i + 1] == result[i + 2]) {
      result[i] = "";
    }
  }

  return result.join("");
    
    
    
};