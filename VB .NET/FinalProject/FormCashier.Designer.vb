<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormCashier
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lblProductName = New System.Windows.Forms.Label()
        Me.lblPrice = New System.Windows.Forms.Label()
        Me.txtProductName = New System.Windows.Forms.TextBox()
        Me.txtPrice = New System.Windows.Forms.TextBox()
        Me.txtQuantity = New System.Windows.Forms.TextBox()
        Me.lblQuantity = New System.Windows.Forms.Label()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.LvCart = New System.Windows.Forms.ListView()
        Me.lblSubtotal = New System.Windows.Forms.Label()
        Me.lblDiscount = New System.Windows.Forms.Label()
        Me.lblTax = New System.Windows.Forms.Label()
        Me.lblTotal = New System.Windows.Forms.Label()
        Me.lblCash = New System.Windows.Forms.Label()
        Me.txtDiscount = New System.Windows.Forms.TextBox()
        Me.txtCash = New System.Windows.Forms.TextBox()
        Me.lblChange = New System.Windows.Forms.Label()
        Me.btnPay = New System.Windows.Forms.Button()
        Me.btnPrint = New System.Windows.Forms.Button()
        Me.btnClear = New System.Windows.Forms.Button()
        Me.btnRemove = New System.Windows.Forms.Button()
        Me.cboPayment = New System.Windows.Forms.ComboBox()
        Me.lblPaymentMethod = New System.Windows.Forms.Label()
        Me.txtSearch = New System.Windows.Forms.TextBox()
        Me.btnSearch = New System.Windows.Forms.Button()
        Me.btnBack = New System.Windows.Forms.Button()
        Me.lblUserInfo = New System.Windows.Forms.Label()
        Me.btnLogout = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblProductName
        '
        Me.lblProductName.AutoSize = True
        Me.lblProductName.Location = New System.Drawing.Point(132, 76)
        Me.lblProductName.Name = "lblProductName"
        Me.lblProductName.Size = New System.Drawing.Size(99, 16)
        Me.lblProductName.TabIndex = 0
        Me.lblProductName.Text = "Product Name: "
        '
        'lblPrice
        '
        Me.lblPrice.AutoSize = True
        Me.lblPrice.Location = New System.Drawing.Point(187, 120)
        Me.lblPrice.Name = "lblPrice"
        Me.lblPrice.Size = New System.Drawing.Size(44, 16)
        Me.lblPrice.TabIndex = 1
        Me.lblPrice.Text = "Price: "
        '
        'txtProductName
        '
        Me.txtProductName.Location = New System.Drawing.Point(237, 73)
        Me.txtProductName.Name = "txtProductName"
        Me.txtProductName.Size = New System.Drawing.Size(222, 22)
        Me.txtProductName.TabIndex = 2
        '
        'txtPrice
        '
        Me.txtPrice.Location = New System.Drawing.Point(237, 117)
        Me.txtPrice.Name = "txtPrice"
        Me.txtPrice.Size = New System.Drawing.Size(222, 22)
        Me.txtPrice.TabIndex = 3
        '
        'txtQuantity
        '
        Me.txtQuantity.Location = New System.Drawing.Point(237, 164)
        Me.txtQuantity.Name = "txtQuantity"
        Me.txtQuantity.Size = New System.Drawing.Size(222, 22)
        Me.txtQuantity.TabIndex = 5
        '
        'lblQuantity
        '
        Me.lblQuantity.AutoSize = True
        Me.lblQuantity.Location = New System.Drawing.Point(170, 167)
        Me.lblQuantity.Name = "lblQuantity"
        Me.lblQuantity.Size = New System.Drawing.Size(61, 16)
        Me.lblQuantity.TabIndex = 4
        Me.lblQuantity.Text = "Quantity: "
        '
        'btnAdd
        '
        Me.btnAdd.Location = New System.Drawing.Point(248, 256)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(155, 60)
        Me.btnAdd.TabIndex = 6
        Me.btnAdd.Text = "Add To Cart"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'LvCart
        '
        Me.LvCart.HideSelection = False
        Me.LvCart.Location = New System.Drawing.Point(881, 38)
        Me.LvCart.Name = "LvCart"
        Me.LvCart.Size = New System.Drawing.Size(495, 425)
        Me.LvCart.TabIndex = 7
        Me.LvCart.UseCompatibleStateImageBehavior = False
        '
        'lblSubtotal
        '
        Me.lblSubtotal.AutoSize = True
        Me.lblSubtotal.Location = New System.Drawing.Point(63, 354)
        Me.lblSubtotal.Name = "lblSubtotal"
        Me.lblSubtotal.Size = New System.Drawing.Size(62, 16)
        Me.lblSubtotal.TabIndex = 8
        Me.lblSubtotal.Text = "Subtotal: "
        '
        'lblDiscount
        '
        Me.lblDiscount.AutoSize = True
        Me.lblDiscount.Location = New System.Drawing.Point(166, 211)
        Me.lblDiscount.Name = "lblDiscount"
        Me.lblDiscount.Size = New System.Drawing.Size(65, 16)
        Me.lblDiscount.TabIndex = 9
        Me.lblDiscount.Text = "Discount: "
        '
        'lblTax
        '
        Me.lblTax.AutoSize = True
        Me.lblTax.Location = New System.Drawing.Point(58, 386)
        Me.lblTax.Name = "lblTax"
        Me.lblTax.Size = New System.Drawing.Size(67, 16)
        Me.lblTax.TabIndex = 10
        Me.lblTax.Text = "SST(6%): "
        '
        'lblTotal
        '
        Me.lblTotal.AutoSize = True
        Me.lblTotal.Location = New System.Drawing.Point(58, 420)
        Me.lblTotal.Name = "lblTotal"
        Me.lblTotal.Size = New System.Drawing.Size(44, 16)
        Me.lblTotal.TabIndex = 11
        Me.lblTotal.Text = "Total: "
        '
        'lblCash
        '
        Me.lblCash.AutoSize = True
        Me.lblCash.Location = New System.Drawing.Point(446, 386)
        Me.lblCash.Name = "lblCash"
        Me.lblCash.Size = New System.Drawing.Size(44, 16)
        Me.lblCash.TabIndex = 12
        Me.lblCash.Text = "Cash: "
        '
        'txtDiscount
        '
        Me.txtDiscount.Location = New System.Drawing.Point(237, 208)
        Me.txtDiscount.Name = "txtDiscount"
        Me.txtDiscount.Size = New System.Drawing.Size(100, 22)
        Me.txtDiscount.TabIndex = 13
        Me.txtDiscount.Text = "0"
        '
        'txtCash
        '
        Me.txtCash.Location = New System.Drawing.Point(496, 383)
        Me.txtCash.Name = "txtCash"
        Me.txtCash.Size = New System.Drawing.Size(100, 22)
        Me.txtCash.TabIndex = 14
        '
        'lblChange
        '
        Me.lblChange.AutoSize = True
        Me.lblChange.Location = New System.Drawing.Point(430, 420)
        Me.lblChange.Name = "lblChange"
        Me.lblChange.Size = New System.Drawing.Size(60, 16)
        Me.lblChange.TabIndex = 15
        Me.lblChange.Text = "Change: "
        '
        'btnPay
        '
        Me.btnPay.Location = New System.Drawing.Point(190, 482)
        Me.btnPay.Name = "btnPay"
        Me.btnPay.Size = New System.Drawing.Size(155, 60)
        Me.btnPay.TabIndex = 16
        Me.btnPay.Text = "Pay"
        Me.btnPay.UseVisualStyleBackColor = True
        '
        'btnPrint
        '
        Me.btnPrint.Location = New System.Drawing.Point(881, 482)
        Me.btnPrint.Name = "btnPrint"
        Me.btnPrint.Size = New System.Drawing.Size(103, 43)
        Me.btnPrint.TabIndex = 17
        Me.btnPrint.Text = "Print Receipt"
        Me.btnPrint.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.Location = New System.Drawing.Point(1273, 482)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(103, 43)
        Me.btnClear.TabIndex = 18
        Me.btnClear.Text = "Clear Cart"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'btnRemove
        '
        Me.btnRemove.Location = New System.Drawing.Point(1086, 482)
        Me.btnRemove.Name = "btnRemove"
        Me.btnRemove.Size = New System.Drawing.Size(103, 43)
        Me.btnRemove.TabIndex = 19
        Me.btnRemove.Text = "Remove Selected"
        Me.btnRemove.UseVisualStyleBackColor = True
        '
        'cboPayment
        '
        Me.cboPayment.FormattingEnabled = True
        Me.cboPayment.Location = New System.Drawing.Point(496, 344)
        Me.cboPayment.Name = "cboPayment"
        Me.cboPayment.Size = New System.Drawing.Size(191, 24)
        Me.cboPayment.TabIndex = 20
        Me.cboPayment.Text = "Choose a Payment Method"
        '
        'lblPaymentMethod
        '
        Me.lblPaymentMethod.AutoSize = True
        Me.lblPaymentMethod.Location = New System.Drawing.Point(376, 347)
        Me.lblPaymentMethod.Name = "lblPaymentMethod"
        Me.lblPaymentMethod.Size = New System.Drawing.Size(114, 16)
        Me.lblPaymentMethod.TabIndex = 21
        Me.lblPaymentMethod.Text = "Payment Method: "
        '
        'txtSearch
        '
        Me.txtSearch.Location = New System.Drawing.Point(612, 120)
        Me.txtSearch.Name = "txtSearch"
        Me.txtSearch.Size = New System.Drawing.Size(206, 22)
        Me.txtSearch.TabIndex = 22
        '
        'btnSearch
        '
        Me.btnSearch.Location = New System.Drawing.Point(651, 176)
        Me.btnSearch.Name = "btnSearch"
        Me.btnSearch.Size = New System.Drawing.Size(128, 45)
        Me.btnSearch.TabIndex = 23
        Me.btnSearch.Text = "Search for Product"
        Me.btnSearch.UseVisualStyleBackColor = True
        '
        'btnBack
        '
        Me.btnBack.Location = New System.Drawing.Point(3, 2)
        Me.btnBack.Name = "btnBack"
        Me.btnBack.Size = New System.Drawing.Size(122, 52)
        Me.btnBack.TabIndex = 24
        Me.btnBack.Text = "Back"
        Me.btnBack.UseVisualStyleBackColor = True
        '
        'lblUserInfo
        '
        Me.lblUserInfo.AutoSize = True
        Me.lblUserInfo.Location = New System.Drawing.Point(245, 20)
        Me.lblUserInfo.Name = "lblUserInfo"
        Me.lblUserInfo.Size = New System.Drawing.Size(0, 16)
        Me.lblUserInfo.TabIndex = 25
        '
        'btnLogout
        '
        Me.btnLogout.Location = New System.Drawing.Point(3, 534)
        Me.btnLogout.Name = "btnLogout"
        Me.btnLogout.Size = New System.Drawing.Size(106, 47)
        Me.btnLogout.TabIndex = 26
        Me.btnLogout.Text = "Logout"
        Me.btnLogout.UseVisualStyleBackColor = True
        '
        'FormCashier
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1429, 582)
        Me.Controls.Add(Me.btnLogout)
        Me.Controls.Add(Me.lblUserInfo)
        Me.Controls.Add(Me.btnBack)
        Me.Controls.Add(Me.btnSearch)
        Me.Controls.Add(Me.txtSearch)
        Me.Controls.Add(Me.lblPaymentMethod)
        Me.Controls.Add(Me.cboPayment)
        Me.Controls.Add(Me.btnRemove)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnPrint)
        Me.Controls.Add(Me.btnPay)
        Me.Controls.Add(Me.lblChange)
        Me.Controls.Add(Me.txtCash)
        Me.Controls.Add(Me.txtDiscount)
        Me.Controls.Add(Me.lblCash)
        Me.Controls.Add(Me.lblTotal)
        Me.Controls.Add(Me.lblTax)
        Me.Controls.Add(Me.lblDiscount)
        Me.Controls.Add(Me.lblSubtotal)
        Me.Controls.Add(Me.LvCart)
        Me.Controls.Add(Me.btnAdd)
        Me.Controls.Add(Me.txtQuantity)
        Me.Controls.Add(Me.lblQuantity)
        Me.Controls.Add(Me.txtPrice)
        Me.Controls.Add(Me.txtProductName)
        Me.Controls.Add(Me.lblPrice)
        Me.Controls.Add(Me.lblProductName)
        Me.Name = "FormCashier"
        Me.Text = "Cashier"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lblProductName As Label
    Friend WithEvents lblPrice As Label
    Friend WithEvents txtProductName As TextBox
    Friend WithEvents txtPrice As TextBox
    Friend WithEvents txtQuantity As TextBox
    Friend WithEvents lblQuantity As Label
    Friend WithEvents btnAdd As Button
    Friend WithEvents LvCart As ListView
    Friend WithEvents lblSubtotal As Label
    Friend WithEvents lblDiscount As Label
    Friend WithEvents lblTax As Label
    Friend WithEvents lblTotal As Label
    Friend WithEvents lblCash As Label
    Friend WithEvents txtDiscount As TextBox
    Friend WithEvents txtCash As TextBox
    Friend WithEvents lblChange As Label
    Friend WithEvents btnPay As Button
    Friend WithEvents btnPrint As Button
    Friend WithEvents btnClear As Button
    Friend WithEvents btnRemove As Button
    Friend WithEvents cboPayment As ComboBox
    Friend WithEvents lblPaymentMethod As Label
    Friend WithEvents txtSearch As TextBox
    Friend WithEvents btnSearch As Button
    Friend WithEvents btnBack As Button
    Friend WithEvents lblUserInfo As Label
    Friend WithEvents btnLogout As Button
End Class
