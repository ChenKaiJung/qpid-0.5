/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
package org.apache.qpid.management.wsdm.muse.serializer;

import java.util.Map;

import javax.xml.namespace.QName;

import org.apache.muse.core.serializer.Serializer;
import org.apache.muse.core.serializer.SerializerRegistry;
import org.apache.muse.util.xml.XmlUtils;
import org.apache.muse.ws.addressing.soap.SoapFault;
import org.apache.qpid.management.wsdm.capabilities.Result;
import org.w3c.dom.Element;

/**
 * Implementation of Muse Serializer for Result type.
 *  
 * @author Andrea Gazzarini
 */
public class InvocationResultSerializer implements Serializer 
{	
	private Serializer _mapSerializer = SerializerRegistry.getInstance().getSerializer(Map.class);
	
	/**
	 * Return a UUID representation of the given xml element.
	 * 
	 * @param xml the element to unmarshal.
	 * @throws SoapFault when the unmarshalling fails.
	 */	
	@SuppressWarnings("unchecked")
	public Object fromXML(Element elementData) throws SoapFault 
	{
		Element outputParameters = XmlUtils.getFirstElement(elementData);
		return new Result((Map<String, Object>) _mapSerializer.fromXML(outputParameters));
	}

	/**
	 * Returns the java type associated to this class.
	 * 
	 * @return the java type associated to this class.
	 */
	public Class<?> getSerializableType() 
	{
		return Result.class;
	}

	/**
	 * Return an xml representation of the given UUID with the given name.
	 * 
	 * @param object the UUID to marshal.
	 * @param qname the qualified (xml) name of the object to use in xml representation.
	 * @return the xml representation of the UUID.
	 * @throws SoapFault when the marshalling fails.
	 */
	public Element toXML(Object obj, QName qname) throws SoapFault 
	{
		Result result = (Result) obj;
		Element root = XmlUtils.createElement(qname);
		if (result.getOutputParameters() != null)
		{
			Element outputSection = SerializerRegistry.getInstance().getSerializer(Map.class).toXML(result.getOutputParameters(), new QName("outputParameters"));
			root.appendChild(outputSection);
		}
		return root;	
	}
}