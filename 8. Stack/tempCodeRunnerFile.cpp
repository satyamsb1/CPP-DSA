char* Stack :: Convert(char *infix)
// {
//     Stack st(strlen(infix)+1);
//     char *postfix=new char[strlen(infix)+1];
//     int i=0, j=0;
//     while(infix[i]!='\0')
//     {
//         if(st.isOperand(infix[i]))
//         {
//             postfix[j++]=infix[i++];
//         }else
//         {
//             if(st.Presidence(infix[i])>st.Presidence(st.StackTop()))
//             {
//                 st.Push(infix[i++]);
//             }
//             else
//             {
//                 postfix[j++]=st.pop();
//             }
//         }
//     }
//     while(!st.IsEmpty())
//     {
//         postfix[j++]=st.pop();
//     }
//     postfix[j]='\0';
//     return postfix;
// }