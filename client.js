const socket = io('http://localhost:5555');

const form=document.getElementById('send-container')
const messageInput=document.getElementById('messageInput')
const messageContainer=document.querySelector('#container')


const append=(message,position)=>{
    const messageElement = document.createElement('div');
    messageElement.innerText=message;
    messageElement.classList.add('message');
    messageElement.classList.add(position);
    messageContainer.append(messageElement); 
}


 form.addEventListener('submit',(e)=>{
    e.preventDefault();
    const message=messageInput.value
    append(`me: ${message}`,'right')
    socket.emit('send',message);
    messageInput.value=''
});
const username =prompt('enter your name');
socket.emit('new-user-joined',(username))

socket.on('user-joined', username=>{
    append(`${username} joined the chat`,'right')
})
socket.on('receive', data=>{
    append(`${data.message}: ${data.username}`,'left')
});
