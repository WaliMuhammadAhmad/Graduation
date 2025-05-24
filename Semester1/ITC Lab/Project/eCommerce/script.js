// fetch and display the data
fetch("https://fakestoreapi.com/products")
  .then((res) => res.json())
  .then((json) => {
    json.forEach((element) => {
      const images = `<img class="img" src="${element.image}" alt="${element.title}">`;
      const title = `<div class="product-heading">${element.title}</div>`;
      const price = `<div class="price">$${element.price}</div>`;
      const button = `<div class="button" onclick='addToCart({title: "${element.title}", price: ${element.price}, image: "${element.image}"})'>add to cart</div>`;

      const markup =
        "<div class='item'> " + images + title + price + button + "</div>";
      document.getElementById("grid").innerHTML += markup;
    });
  })
  .catch((e) => console.log(e));

function setCookie(name, value, days) {
  const d = new Date();
  d.setTime(d.getTime() + days * 24 * 60 * 60 * 1000);
  const expires = "expires=" + d.toUTCString();
  document.cookie = name + "=" + value + ";" + expires + ";path=/";
}

function getCookie(name) {
  const cookie = document.cookie;
  // console.log(cookie);
  const ca = cookie.split(";");
  const nameEQ = name + "=";
  for (let i = 0; i < ca.length; i++) {
    let c = ca[i];
    while (c.charAt(0) == " ") {
      c = c.substring(1);
    }
    if (c.indexOf(nameEQ) == 0) {
      return c.substring(nameEQ.length, c.length);
    }
  }
  return "";
}

function deleteCookie(name) {
  document.cookie = name + "=; Max-Age=-99999999;";
}

let cart = JSON.parse(getCookie("cart") || "[]");

function addToCart(product) {
  cart.push(product);
  setCookie("cart", JSON.stringify(cart), 7);
  alert(`${product.title} added to cart`);
  displayCart();
}

function displayCart() {
  const cartItems = document.getElementById("cart-items");
  cartItems.innerHTML = "";
  let total = 0;

  const uniqueCart = cart.reduce((acc, item) => {
    const existingItem = acc.find(i => i.title === item.title);
    if (existingItem) {
      existingItem.quantity += 1;
    } else {
      item.quantity = 1;
      acc.push(item);
    }
    return acc;
  }, []);

  if (uniqueCart.length === 0) {
    cartItems.innerHTML = "<p class='heading'>Your cart is empty!</p>";
  } else {
    uniqueCart.forEach((item, index) => {
      const itemTotal = item.price * item.quantity;
      total += itemTotal;

      cartItems.innerHTML += `
        <div class="cart-item">
          <img class="cart-img" src="${item.image}" alt="${item.title}">
          <div class="product-heading">${item.title}</div>
          <div class="price">$${itemTotal.toFixed(2)}</div>
          <div>x${item.quantity}</div>
          <div class="button-group">
            <button class="remove-button" onclick="removeFromCart(${index})">Remove</button>
          </div>
        </div>
      `;
    });

    cartItems.innerHTML += `<div class="group">
    <div class="total">Total: $${total.toFixed(2)}</div>
    <a href="checkout.html"><button class="button" >Checkout</button></a>
    </div>`;
  }
}

function displayCartatCheckout() {
  const cartItems = document.getElementById("show-cart");
  console.log(cartItems)
  cartItems.innerHTML = "";
  let total = 0;

  const uniqueCart = cart.reduce((acc, item) => {
    const existingItem = acc.find(i => i.title === item.title);
    if (existingItem) {
      existingItem.quantity += 1;
    } else {
      item.quantity = 1;
      acc.push(item);
    }
    return acc;
  }, []);

  console.log(uniqueCart)

  if (uniqueCart.length === 0) {
    cartItems.innerHTML = "<p class='heading'>Your cart is empty!</p>";
  } else {
    uniqueCart.forEach((item, index) => {
      const itemTotal = item.price * item.quantity;
      total += itemTotal;

      cartItems.innerHTML += `
        <div class="cart-item">
          <img class="cart-img" src="${item.image}" alt="${item.title}">
          <div class="product-heading">${item.title}</div>
          <div class="price">$${itemTotal.toFixed(2)}</div>
          <div>x${item.quantity}</div>
          <div class="button-group">
            <button class="remove-button" onclick="removeFromCart(${index})">Remove</button>
          </div>
        </div>
      `;
    });

    cartItems.innerHTML += `<div class="group">
    <div class="total">Total: $${total.toFixed(2)}</div>
    <a href="checkout.html"><button class="button" >Checkout</button></a>
    </div>`;
  }
}

// displayCart()

function removeFromCart(index) {
  cart.splice(index, 1);
  setCookie("cart", JSON.stringify(cart), 7);
  displayCart();
}

document.addEventListener("DOMContentLoaded", () => {
  displayCart();
  displayCartatCheckout();
});

// Modal //

var modal = document.getElementById("myModal");
var btn = document.getElementById("myBtn");
var span = document.getElementsByClassName("close")[0];
btn.onclick = function() {
  modal.style.display = "block";
}

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
  modal.style.display = "none";
}