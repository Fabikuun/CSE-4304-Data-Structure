for(int i=0; i<=line.length(); i++){
        if(i==line.length() || line[i]==' '){
            if(!word.empty()){
                insert(word);
                word="";
            }
            else word+=line[i];
        }
    }